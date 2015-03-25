#include "XML/pugiconfig.hpp"
#include "XML/pugixml.hpp"

#ifndef SRC_XMLWRITER_H_
#define SRC_XMLWRITER_H_

class xmlWriter {
public:
	xmlWriter();
	void crearXML();
private:
	 pugi::xml_document doc;
};

#endif /* SRC_XMLWRITER_H_ */
