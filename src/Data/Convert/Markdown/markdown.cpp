/******************************************************************************
 * MODULE     : markdown.cpp
 * DESCRIPTION: Markdown to TMU tree conversion (Placeholder)
 ******************************************************************************/

#include "markdown.hpp"
#include "tree_helper.hpp"
#include "md4c.h" // Testing md4c include

tree markdown_to_tree(string s) {
  // TODO: Phase 2 - Implement md4c AST parsing and mapping to Mogan's tree
  // For now, this is a placeholder that returns a basic verbatim tree or text
  // just to prove the C++ binding and build works.
  
  return tree(TUPLE, "document", s);
}
