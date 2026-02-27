%% ========================================================
%  Please copy your function definition below, in the place between line 4 and line 8 (from PascalTriangle.m)
%  FUNCTION START
%% ========================================================
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


%% ========================================================
%  FUNCTION END
%% ========================================================
%% Main script (do NOT modify)
row = input('row=');
A = PascalTriangle(row);
for i = row:-1:1
    current_row = A(i,:);
    non_zero_elements = current_row(current_row ~= 0);
    fprintf(repmat(' ',1,row - i));
    fprintf('%d ', non_zero_elements);
    fprintf('\n');
end