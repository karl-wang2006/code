function f= PascalTriangle(n)
  A=zeros(n,2*n-1);
  A(1,n)=1;
  A(n,1)=1;
  A(n,2*n-1)=1;
  for i=2:n
      for j=2:(2*n-2)
      A(i,j)=A(i-1,j-1)+A(i-1,j+1);
      end
  end
 f=A;
end