#include <windows.h>
#include <iostream>
#include <osg/MatrixTransform>
#include <osgText/Text>

#include "Printer.h"

Common::Printer::Printer() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
{
}

Common::Printer::~Printer()
{
}

void Common::Printer::apply(osg::Node& node)
{
	std::string s;
	for (unsigned int i = 0; i < getNodePath().size(); i++) s += "|--";

	std::cout << s << "Node -> " << node.getName() << " :: " << node.libraryName() << "::" << node.className() << std::endl;

	if (osg::MatrixTransform* pMT = dynamic_cast<osg::MatrixTransform*>(&node))
	{
		osg::Matrix m = pMT->getMatrix();
		std::cout << s << "    " << m.ptr()[0] << ", " << m.ptr()[1] << ", " << m.ptr()[2] << ", " << m.ptr()[3] << std::endl;
		std::cout << s << "    " << m.ptr()[4] << ", " << m.ptr()[5] << ", " << m.ptr()[6] << ", " << m.ptr()[7] << std::endl;
		std::cout << s << "    " << m.ptr()[8] << ", " << m.ptr()[9] << ", " << m.ptr()[10] << ", " << m.ptr()[11] << std::endl;
		std::cout << s << "    " << m.ptr()[12] << ", " << m.ptr()[13] << ", " << m.ptr()[14] << ", " << m.ptr()[15] << std::endl;
	}

	if (osgText::Text* pText = dynamic_cast<osgText::Text*>(&node))
	{
		std::cout << s << "   Text==" << pText->getText().createUTF8EncodedString() << std::endl;
	}

	traverse(node);
}
