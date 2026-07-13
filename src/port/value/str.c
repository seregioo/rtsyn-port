#include <stdlib.h>
#include <string.h>

#include "rtsyn/internal/port/value.h"
#include "rtsyn/internal/port/value/str.h"

rtsyn_port_value_t *
rtsyn_port_value_create_str()
{
    return rtsyn_port_value_create(RTSYN_PORT_VALUE_STR);
}

rtsyn_str_t *
rtsyn_port_value_str_create()
{
    char *str_content = (char *)calloc(RTSYN_PORT_VALUE_STRING_MAX_SIZE, sizeof(char));

    if (!str_content)
    {
        return nullptr;
    }

    rtsyn_str_t *rtsyn_str = (rtsyn_str_t *)malloc(sizeof(rtsyn_str_t));
    if (!rtsyn_str)
    {
        free(str_content);
        return nullptr;
    }

    rtsyn_str->string = str_content;
    rtsyn_str->str_max_size = RTSYN_PORT_VALUE_STRING_MAX_SIZE;

    return rtsyn_str;
}

void
rtsyn_port_value_str_destroy(rtsyn_str_t *str_value)
{
    if (!str_value)
    {
        return;
    }

    free(str_value->string);
    free(str_value);
}

bool
rtsyn_port_value_str_get(const rtsyn_port_value_t *port_value, char *out)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_STR) || !out)
    {
        return false;
    }

    const rtsyn_str_t *rtsyn_str = (const rtsyn_str_t *)port_value->value_data;
    if (!rtsyn_str || !rtsyn_str->string)
    {
        return false;
    }

    const size_t needed = strlen(rtsyn_str->string) + 1;
    memcpy(out, rtsyn_str->string, needed);
    out[needed - 1] = '\0';
    return true;
}

size_t
rtsyn_port_value_str_size_get()
{
    return (size_t)RTSYN_PORT_VALUE_STRING_MAX_SIZE * sizeof(char);
}

bool
rtsyn_port_value_str_set(rtsyn_port_value_t *port_value, const char *new_value)
{
    if (!port_value || !rtsyn_port_value_is_type(port_value, RTSYN_PORT_VALUE_STR) || !new_value)
    {
        return false;
    }

    rtsyn_str_t *port_value_str = (rtsyn_str_t *)port_value->value_data;

    uint32_t str_len = port_value_str->str_max_size - 1;

    strncpy(port_value_str->string, new_value, str_len);

    port_value_str->string[str_len] = '\0';

    return true;
}
