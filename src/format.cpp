
#include "wk/geometry-handler.h"
#include "wk/wkb-reader.h"
#include "wk/wkt-streamer.h"
#include "wk/wkt-writer.h"

#include <Rcpp.h>
#include "wk/rcpp-io.h"
#include "wk/sexp-reader.h"
using namespace Rcpp;

class WKMaxCoordinatesException: public WKParseException {
public:
  static const int CODE_HAS_MAX_COORDS = 32453;
  WKMaxCoordinatesException(): WKParseException(CODE_HAS_MAX_COORDS) {}
};


class WKFormatter: public WKTWriter {
public:
  WKFormatter(WKStringExporter& exporter, int maxCoords):
    WKTWriter(exporter), maxCoords(maxCoords), thisFeatureCoords(0) {}

  void nextFeatureStart(size_t featureId) {
    this->thisFeatureCoords = 0;
    WKTWriter::nextFeatureStart(featureId);
  }

  void nextCoordinate(const WKGeometryMeta& meta, const WKCoord& coord, uint32_t coordId) {
    WKTWriter::nextCoordinate(meta, coord, coordId);
    this->thisFeatureCoords++;
    if (this->thisFeatureCoords >= this->maxCoords) {
      throw WKMaxCoordinatesException();
    }
  }

  bool nextError(WKParseException& error, size_t featureId) {
    if (error.code() == WKMaxCoordinatesException::CODE_HAS_MAX_COORDS) {
      this->exporter.writeConstChar("...");
      this->nextFeatureEnd(featureId);
      return true;
    } else {
      return false;
    }
  }

private:
  int maxCoords;
  int thisFeatureCoords;
};

Rcpp::CharacterVector cpp_format_base(WKReader& reader, int maxCoords) {
  WKCharacterVectorExporter exporter(reader.nFeatures());
  WKFormatter formatter(exporter, maxCoords);
  reader.setHandler(&formatter);
  while (reader.hasNextFeature()) {
    checkUserInterrupt();
    reader.iterateFeature();
  }

  return exporter.output;
}

// [[Rcpp::export]]
Rcpp::CharacterVector cpp_format_wkb(Rcpp::List wkb, int maxCoords) {
  WKRawVectorListProvider provider(wkb);
  WKBReader reader(provider);
  return cpp_format_base(reader, maxCoords);
}

// [[Rcpp::export]]
Rcpp::CharacterVector cpp_format_wkt(CharacterVector wkt, int maxCoords) {
  WKCharacterVectorProvider provider(wkt);
  WKTStreamer reader(provider);
  return cpp_format_base(reader, maxCoords);
}

// [[Rcpp::export]]
Rcpp::CharacterVector cpp_format_wksxp(List wksxp, int maxCoords) {
  WKSEXPProvider provider(wksxp);
  WKSEXPReader reader(provider);
  return cpp_format_base(reader, maxCoords);
}
