%% ========================================================
%  Please copy your function definition below, in the place between line 4 and line 8 (from FibonacciSequence.m)
%  FUNCTION START
%% ========================================================

function f= FibonacciSequence(n)
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

%% ========================================================
%  FUNCTION END
%% ========================================================
%% Main script (do NOT modify)
row = input('');
A = FibonacciSequence(row);
fprintf('%d ', A);
fprintf('\n');
