# Target for the expression processing library
add_library(expression-lib STATIC
		infix_to_postfix_converter.cpp
		infix_to_postfix_converter.h)

target_sources(
	expression-lib
	PRIVATE
		"expression.cpp"
		"expression.h"
)