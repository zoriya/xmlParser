# XmlParser

An xml parser in C.

# Dependencies
To compile, you'll need gcc, ar rc and make.

### System calls
Open, Close, Read, Stat

## Build
Simple clone the repo and use the command ``make``.

## Usage
Use ``xml_parse(path)`` to parse the whole xml.

Use ``xml_getnode(xml, node_name)`` to get the first node with the name you inputed.

Use ``xml_getproperty(key)`` to get an attribute of the xml.

## Unsuported yet
Attributes with semi quotes (') instead of quotes (")

Comments

String containing multiples following spaces.

String containing \n, \r or \t (theses specials chars are removed)
