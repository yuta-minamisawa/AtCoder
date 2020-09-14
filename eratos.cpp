int v[n];

for(int i=0;i<n;i++)v[i]=0;
for(int i=2;i<n;i++){
  if(v[i])continue;
  for(int j=2*i;j<n;j+=i){
    v[j]=i;
  }
}