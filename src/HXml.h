// HXml.h

#pragma once
#include "../interface/HeeksObj.h"
#include "../tinyxml/tinyxml.h"

class HXml: public HeeksObj{
private:
	static wxIcon* m_icon;

public:
	TiXmlElement m_element;

	~HXml(void);
	HXml(TiXmlElement* pElem);

	// HeeksObj's virtual functions
	int GetType()const{return XmlType;}
	const wxChar* GetShortString(void)const;
	const wxChar* GetTypeString(void)const{return _("Xml");}
	HeeksObj *MakeACopy(void)const;
	wxString GetIcon(){return _T("xml");}
	void GetProperties(std::list<Property *> *list);
	void CopyFrom(const HeeksObj* object){operator=(*((HXml*)object));}
	void WriteXML(TiXmlNode *root);

	static HeeksObj* ReadFromXMLElement(TiXmlElement* pElem);

};