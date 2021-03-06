/**
 * @file parser.h
 * @author rick
 * @date 30.07.20
 * @brief File for the Parser implementation
 */

#ifndef WAITUI_PARSER_H
#define WAITUI_PARSER_H

#include "waitui/parser_helper.h"

#include <waitui/ast.h>
#include <waitui/str.h>


// -----------------------------------------------------------------------------
//  Public types
// -----------------------------------------------------------------------------

/**
 * @brief Type for the Parser.
 */
typedef struct parser {
    FILE *sourceFile;
    str sourceFileName;
    str workingDirectory;
    unsigned int debug;
    parser_extra_parser extraParser;
    parser_extra_lexer extraLexer;
} parser;


// -----------------------------------------------------------------------------
//  Public defines
// -----------------------------------------------------------------------------

#define PARSER_DEBUG_NONE 0U
#define PARSER_DEBUG_LEXER 1U
#define PARSER_DEBUG_PARSER 2U


// -----------------------------------------------------------------------------
//  Public functions
// -----------------------------------------------------------------------------

/**
 * @brief Create a Parser.
 * @param[in] sourceFileName The source file to begin the parsing with
 * @param[in] workingDirectory The working directory to search other files in
 * @param[in] debug The debug level of the parser
 * @return A pointer to Parser or NULL if memory allocation failed
 */
extern parser *parser_new(str sourceFileName, str workingDirectory,
                          unsigned int debug);

/**
 * @brief Destroy a Parser.
 * @param[in,out] this The Parser to destroy
 */
extern void parser_destroy(parser **this);

/**
 * @brief Parse the source file.
 * @param[in] this The parser to run.
 * @retval 1 Ok
 * @retval 0 Error while parsing
 */
extern int parser_parse(parser *this);

/**
 * @brief Return the resulting waitui_ast after parsing.
 * @param[in] this The parser to retrieve the waitui_ast from
 * @return A pointer to a AST or NULL if parsing failed or hasn't run
 */
extern waitui_ast *parser_get_ast(parser *this);

#endif //WAITUI_PARSER_H
