#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lcs(string A, string B){
	int m = A.length();
	int n = B.length();
	vector<vector<int>> dp((A.length()+1), vector<int>((B.length()+1), 0));
	
	int** parr = new int*[m+1];
	
	for(int i=0; i<n+1; i++){
		parr[i] = new int[n+1];
	}
	
	for(int i=1; i<m+1; i++){
		for(int j=1; j<n+1; j++){
			if(A[i-1] == B[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				parr[i][j] = 0;
								
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(max(dp[i-1][j],dp[i][j-1]) == dp[i-1][j]){
					parr[i][j] = 1;
				}
				else{
					parr[i][j] = -1;
				}
			}
		}
	}
	
	cout<<endl;
	
	int i = m, j = n;
	while(i != 0 && j != 0){
		if(parr[i][j] == 0){
			cout<<A[i-1];
		}	
		if(parr[i][j] == 1){
			i--;
		}
		else if(parr[i][j] == -1){
			j--;
		}
		else{
			i--;
			j--;
		}
	}
	
	cout<<endl;
	
	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\nThe length of longest common subsequence: "<<dp[m][n]<<endl;
	
	return dp[m][n];
}

int main() {
	lcs("ABCDABC","ABCDACD");
	return 0;

}
