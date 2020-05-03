# XmlParser

An xml parser in C.

## Build
Simple clone the repo and use the command ``make``. A statically linkable library will be created.

## Usage
Use ``xml_parse(path)`` to parse the whole xml.

Use ``xml_getnode(xml, node_name)`` to get the first node with the name you inputed.


### Data usage
Here is the full list of helper function that will allow you to simply use the data:


```bool xml_hasproperty(node *n, const char *key);``` Check if a property is present or not (do not check the value)


```char *xml_getproperty(node *n, const char *key);``` Return a malloced string property and parse special characters. Ex: \n will be transformed to a new line char.



```char *xml_gettempprop(node *n, const char *key);``` Return a pointer to the node's raw property. Special characters are not evaluated. Warning: you should not free it.


```char *xml_gettmpstring(node *n, const char *key, char *def);``` Same as above but if the string is not found, ``def`` is returned instead of ``NULL``


```int xml_getintprop(node *n, const char *key);``` Return the property as a int. If the value is not found, 0 is returned.


```int xml_getbinaprop(node *n, const char *key);``` Interpret the property as a binnary int value. If the value is not found, 0 is returned.


```int xml_gethexaprop(node *n, const char *key);``` Interpret the property as an hexadecimal int value. If the value is not found, 0 is returned.

```float xml_getfloatprop(node *n, const char *key);``` Return the property as a float. If the value is not found, 0 is returned.


```int xml_getchildcount(node *n);``` Return the total number of childs a node has.


```int xml_getchildcount_filtered(node *n, char *name);``` Return the number of child with the name ``name`` a node has.


```bool xml_getbool(node *n, const char *key, bool default_value);``` Interpret the property as a boolean. If the value is not found, ``default_value`` is returned.

### Free


And do not forget to free the parsed xml when you do not need it anymore with the function: ``void xml_destroy(node *n);``

## Unsuported
Attributes with semi quotes (') instead of quotes (")

Comments
