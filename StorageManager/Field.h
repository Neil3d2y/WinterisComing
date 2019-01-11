//
// Created by Neil3d2y on 3/12/2017.
//

#ifndef TINYSQL_FIELD_H
#define TINYSQL_FIELD_H

using namespace std;

/* A field type can either be INT or STR20
 * Usage: When you specify the schema, you need the following definition of field types.
 *        When you access a field, check the schema about the field type first,
 *        and determine whether to access variable "str" or "integer" from the "union"
 */

enum FIELD_TYPE { INT, STR20 };

union Field {
public:
    string* str;
    int integer;
    Field() {}
};


#endif //TINYSQL_FIELD_H
