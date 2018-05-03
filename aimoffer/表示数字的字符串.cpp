/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
以前做过一次，当时查看的方法是用状态机制来实现，这次忘记了状态机制，采用正向暴力破解的方法来实现，但是还是状态机制比较容易理解。
*/

//version 1(3 ms)
class Solution {
public:
    bool isNumeric(char* string)
    {
        int pos=0;
        int co = 0;
        //skip ' '
        while(*(string+pos) == ' ')pos++;
        if(*(string+pos) == '+' || *(string+pos) == '-')pos++;
        if(*(string+pos) >='1' && *(string+pos)<='9')pos++;
        else if(*(string+pos) == '0' && *(string+pos+1) == '.'){
            pos += 2;
            co++;
        }
        else if(*(string+pos) == '.'){ pos++; co++; }
        else return false;
        while(*(string+pos) >='0' && *(string+pos)<='9') pos++;
        if(*(string+pos) == '.') { pos++; co++;}
        while(*(string+pos) >='0' && *(string+pos)<='9') pos++;
        if(*(string+pos) =='e' || *(string+pos)=='E') {
            pos++;
            if(*(string+pos) == '+' || *(string+pos) == '-') pos++;
        }
        else if(*(string+pos) == '.') { pos++; co++;}
        while(*(string+pos) >='0' && *(string+pos)<='9') pos++;
        while(*(string+pos) == ' ')pos++;
        if(*(string+pos-1) == 'e' ||*(string+pos) == 'E' || *(string+pos)=='.') return false;
        if(*(string+pos) == '\0' && co <= 1) return true;
        return false;
    }

};