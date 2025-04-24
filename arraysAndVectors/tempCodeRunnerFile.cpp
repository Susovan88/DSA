int n=v.size();
	int i=0,j=n-1;
	while(i<=j){
		if(v[i]==0) i++;
		if(v[j]==1) j--;
		if(i>j) break;
		if(v[i]==1 && v[j]==0){
			int temp=v[i];
			v[i]=0;
			v[j]=1;
			i++;
		  j--;
		}
	}