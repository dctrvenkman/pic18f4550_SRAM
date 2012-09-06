/*
 * File:   cliParser.h
 * Author: Ryan Mamone
 *
 * Created on November 11, 2010, 4:31 PM
 */

#ifndef CLIPARSER_H_
#define CLIPARSER_H_

#define CLI_PARSER_BUFFER_SIZE  32
#define CLI_MAX_PARAM_COUNT     2//5
#define CLI_MAX_CMD_COUNT       10//32
#define CLI_TERM_CHARACTER      '\r'
#define CLI_DEFAULT_PROMPT      '>'

typedef enum
{
    CLI_RETURN_SUCCESS,
    CLI_RETURN_FAIL,
    CLI_RETURN_TOO_MANY_CMDS,
    CLI_RETURN_TOO_MANY_PARAMS,
    CLI_RETURN_TOO_FEW_PARAMS,
    CLI_RETURN_CMD_NOT_FOUND,
    CLI_RETURN_CMD_EXECUTED,
    CLI_RETURN_STILL_PARSING,
    CLI_RETURN_NULL_CMD,
    CLI_RETURN_QTY
}cliReturn_t;

typedef enum
{
    NONE, /* DEBUG */
    CLI_PARAM_TYPE_UCHAR,
    CLI_PARAM_TYPE_SCHAR,
    CLI_PARAM_TYPE_UINT,
    CLI_PARAM_TYPE_SINT,
    CLI_PARAM_TYPE_FLOAT,
    CLI_PARAM_TYPE_VPTR,
    CLI_PARAM_TYPE_QTY
}cliParamType_t;

typedef struct
{
    const char* name;
    cliParamType_t type;
}cliParam_t;

/* Prototype for cli command callback */
typedef void (*cliCmdCbk)(const char* cmdName, char** params, unsigned char numParams);

void cliInit(void);
cliReturn_t cliParseInputChar(char c);
cliReturn_t cliRegisterCmd(const char* name, cliCmdCbk callback, unsigned char numParams,
                    cliParam_t params[]);

#define CLI_REGISTER_CMD(name, callback, params) \
    cliRegisterCmd(name, callback, sizeof(params)/sizeof(cliParam_t), params)

#endif /* CLIPARSER_H_ */
