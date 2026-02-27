function f=FibonacciSequence(n)
A(1,1)=1;
A(1,2)=1;

  for i=3:n
      A(1,i)=A(1,i-1)+A(1,i-2);
  end
  f=A;
  if n==1
      f=1;
  end
end




