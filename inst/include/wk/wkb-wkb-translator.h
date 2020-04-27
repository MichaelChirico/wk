
#ifndef WK_WKB_WKB_TRANSLATOR
#define WK_WKB_WKB_TRANSLATOR

#include "wk/translator.h"
#include "wk/wkb-writer.h"
#include "wk/wkb-reader.h"

class WKBWKBTranslator: WKBReader, public WKTranslator {
public:
  WKBWKBTranslator(BinaryReader& reader, BinaryWriter& writer): WKBReader(reader), writer(writer) {

  }

  // expose these as the public interface
  virtual bool hasNextFeature() {
    this->writer.seekNextFeature();
    return WKBReader::hasNextFeature();
  }

  virtual void iterateFeature() {
    WKBReader::iterateFeature();
  }

  void setEndian(unsigned char endian) {
    this->writer.setEndian(endian);
  }

protected:
  WKBWriter writer;
  WKGeometryType newGeometryType;

  virtual void nextNull(size_t featureId) {
    this->writer.writeNull();
  }

  void nextGeometryType(const WKGeometryType geometryType, uint32_t partId) {
    // make a new geometry type based on the creation options
    this->newGeometryType = this->getNewGeometryType(geometryType);

    // write endian and new geometry type
    this->writer.writeEndian();
    this->writer.writeUint32(this->newGeometryType.ewkbType);
  }

  void nextSRID(const WKGeometryType geometryType, uint32_t partId, uint32_t srid) {
    if (this->newGeometryType.hasSRID) {
      this->writer.writeUint32(srid);
    }
  }

  void nextGeometry(const WKGeometryType geometryType, uint32_t partId, uint32_t size) {
    // only points aren't followed by a uint32 with the number of [rings, coords, geometries]
    if (geometryType.simpleGeometryType != SimpleGeometryType::Point) {
      this->writer.writeUint32(size);
    }

    WKBReader::nextGeometry(geometryType, partId, size);
  }

  void nextLinearRing(const WKGeometryType geometryType, uint32_t ringId, uint32_t size) {
    this->writer.writeUint32(size);
    WKBReader::nextLinearRing(geometryType, ringId, size);
  }

  void nextCoordinate(const WKCoord coord, uint32_t coordId) {
    this->writer.writeDouble(coord.x);
    this->writer.writeDouble(coord.y);
    if (this->newGeometryType.hasZ && coord.hasZ) {
      this->writer.writeDouble(coord.z);
    }
    if (this->newGeometryType.hasM && coord.hasM) {
      this->writer.writeDouble(coord.m);
    }
  }
};

#endif
