#include "pch.h"
#include "Element.h"
#include "Variable.h"
#include "Exceptions.h"

Variable Element::run(Blackboard& blackboard) throw(ExceptionBase){
	if (type == EMPTY)
	{
		return Variable();
	}

	double temp = atoi(value.c_str());//try to get num value
	if (temp == 0 &&
		value[0] != '0')//if can't
	{		
		if (value[0] == '"') {//check on string
			auto valCopy = value;
			valCopy.erase(valCopy.begin());
			valCopy.erase(valCopy.end() - 1);
			return Variable(valCopy, "rValue", "string");
		}
		for (size_t i = 0; i < blackboard.vars.size(); ++i)//check on variable
			if (value == blackboard.vars[i].getName()) {
				return blackboard.vars[i];
			}
		throw VariableNotFoundException("Using of undeclared variable", line, column);
	}
	else
	{
		if (value.find('.') == std::string::npos)//convert number on int or double
			return Variable(value, "rValue", "int");
		else return Variable(value, "rValue", "double");
	}
}

bool Element::isTrue() {
	if (value != "0" &&
		value != "false")
		return true;
	else return false;
}

string Element::getValue() const {
	return value;
}

void Element::setValue(string val) {
	value = val;
}

ElemType Element::getType() const{
	return type;
}