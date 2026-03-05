%% ========================================================
%  Please copy your function definition below, in the place between line 4 and line 8 (from update_board.m)
%  FUNCTION START
%% ========================================================
function board = update_board(board)
   
    ball_idx = find(board >= 6 & board <= 9);
    [ball_row, ball_column] = ind2sub(size(board), ball_idx);
    direction = board(ball_row, ball_column);
   
    rotdir = [6 2; 7 3; 8 0; 9 1];
    three=[6 8;7 9;8 6;9 7];
    two=[6 7;7 8;8 9;9 6];
    one=[6 9;7 6;8 7;9 8];
    three1=three(three(:,1)==direction,2);
    two1=two(two(:,1)==direction,2);
    one1=one(one(:,1)==direction,2);
    k = rotdir(rotdir(:,1)==direction, 2);
    R = rot90(board, k);
    idx=find(R >= 6 & R <= 9);
    [rr, cc] = ind2sub(size(R), idx);  
    
    [m, n] = size(R);
    next_row = rr + 1;
    next_column = cc + 1;

    
    if  R(next_row, next_column) == 5 && next_row==m &&next_column~=n
    
        if R(next_row-1,next_column)~=0 
           R(rr, cc) = 0;
           R(rr,cc)=three1;
           R(next_row-1,next_column)=R(next_row-1,next_column)-1;
        elseif R(next_row-1,next_column)==0 
            R(rr, cc) = 0;
           R(rr,cc+1)=one1;
        end
    elseif R(next_row, next_column) ==5 && next_row~=m && next_column==n  
        if R(next_row, next_column-1)~=0
           R(rr, cc) = 0;
           R(rr,cc)=three1;
           R(next_row,next_column-1)=R(next_row,next_column-1)-1;
        elseif R(next_row, next_column-1)==0
            R(rr, cc) = 0;
           R(rr+1,cc)=two1;
        end
    elseif R(next_row, next_column) ==5 && next_row==m && next_column==n 
        R(rr, cc) = 0;
        R(rr,cc)=three1;
    end
    
    if R(next_row, next_column) ~=0 && next_row~=m &&next_column~=n
       if  R(next_row-1,next_column)~=0 && R(next_row, next_column-1)~=0
           R(rr, cc) = 0;
           R(rr,cc)=three1;
           R(next_row-1,next_column)=R(next_row-1,next_column)-1;
           R(next_row, next_column-1)=R(next_row, next_column-1)-1;
           R(next_row, next_column)=R(next_row, next_column)-1;
       elseif  R(next_row-1,next_column)==0 && R(next_row, next_column-1)~=0
           R(rr, cc) = 0;
           R(rr,cc+1)=one1;
           R(next_row, next_column-1)=R(next_row, next_column-1)-1;
           R(next_row, next_column)=R(next_row, next_column)-1;
       elseif  R(next_row-1,next_column)~=0 && R(next_row, next_column-1)==0
           R(rr, cc) = 0;
           R(rr+1,cc)=two1;
           R(next_row-1,next_column)=R(next_row-1,next_column)-1;
           R(next_row, next_column)=R(next_row, next_column)-1;
       elseif R(next_row-1,next_column)==0 && R(next_row, next_column-1)==0 
           R(rr, cc) = 0;
           R(rr,cc)=three1;
           R(next_row, next_column)=R(next_row, next_column)-1;
       end
    end

    if R(next_row, next_column) ==0
    R(rr+1,cc+1)=R(rr, cc);
    R(rr, cc) = 0;
    end
    
    board = rot90(R, -k);
end


%% ========================================================
%  FUNCTION END
%% ========================================================
%% Main script (do NOT modify)
A=input("");
B=update_board(A);
disp(B);