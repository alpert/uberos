/** strlen
 * Calculates the lenght of a given string
 *
 * @param str  The string
 * return      The lenght of given string
 */
unsigned int strlen(const char* str)
{
    unsigned int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}
