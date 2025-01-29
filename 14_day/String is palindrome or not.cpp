
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *str) {
    int length = strlen(str);
    int i;
    for(i = 0; i < length / 2; i++) {
        if(str[i] != str[length - i - 1]) {
            
            return false;
        }
    }
     return true ;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char str[1000];
        scanf("%s", str);
        isPalindrome(str);
    }
    return 0;
}




/*// Return true if the string is palindrome, else return false
#include<bits/stdc++.h>

bool isPalindrome(string str) {
  // Write your code here
   int length = str.length();
    int i;
    for(i = 0; i < length / 2; i++) 
    {
        if(str[i] != str[length - i - 1]) 
        {
            return false;
            
        }
    }
   return true;
}
*/