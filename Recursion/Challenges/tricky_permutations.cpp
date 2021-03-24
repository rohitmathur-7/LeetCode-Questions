/* QUES: 
Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

Input Format
The first and only line of the test case contains the input string.

Constraints
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

Sample Input
ABA

Sample Output
AAB
ABA
BAA

Explanation
The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We skip the repeating "AAB" permutation and only print it in once. Also we print the final output in lexicographical order.
*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(string s,int i,set<string> &ans){
	//base case	
	if(s[i]=='\0'){
		ans.insert(s);
		return;
	}
	//rec case
	for(int j=i;s[j]!='\0';j++){
		swap(s[i],s[j]);
		solve(s,i+1,ans);
		//Backtracking - To restore the original array
		swap(s[i],s[j]);
	}
	return;
}

//Method 2 - using next_permutation function
void solve_using_next_permutation(string s){
    sort(s.begin(),s.end());
    int n=s.size();
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}


int main(){
    string s;
    cin>>s;
    //Method 1 - Recursion(Backtracking)
    // set<string> ans;
    // solve(s,0,ans);
    // for(auto x:ans) cout<<x<<endl;

    //Method 2 - using next_permuatation function
    // solve_using_next_permutation(s);

    return 0;
}