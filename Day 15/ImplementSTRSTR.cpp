#include <bits/stdc++.h>
using namespace std;
 
// INT_MAX is used as prime number to avoid collision
void search(string pat, string txt, int INT_MAX)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int hashPat = 0; // hash value for pattern
    int hashTxt = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(256, M-1)%INT_MAX"
    for (i = 0; i < M - 1; i++)
        h = (h*256) % INT_MAX;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        hashPat = (256 * hashPat + pat[i]) % INT_MAX;
        hashTxt = (256 * hashTxt + txt[i]) % INT_MAX;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if ( hashPat == hashTxt )
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                {
                  break;
                }
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
           
            if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            hashTxt = (256*(hashTxt - txt[i]*h) + txt[i+M])%INT_MAX;
            // We might get negative value of t, converting it
            // to positive
            if (hashTxt < 0)
            hashTxt = (hashTxt + INT_MAX);
        }
    }
}