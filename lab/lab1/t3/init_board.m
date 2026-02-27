function board = init_board()
a=input("row=");
b=input("column=");
p=input(" block generation rate=");
if a<5
    disp(" too small, row is fixed at 5");
    a=5;
end
if b<5
    disp( "too small, column is fixed at 5");
    b=5;
end
if p<0.1||p>0.9
    disp(" too small or too large, range[0.1,0.9]");
    p=input(" block generation rate=");
end

board=zeros(a+2,b+2);
for i=1:(b+2)
    board(1,i)=5;
    board(a+2,i)=5;
end
for j=1:(a+2)
    board(j,1)=5;
    board(j,b+2)=5;
end

blocknumber=floor(a*b*p);
region=board(2:a+1,2:b+1);
regionnumber=numel(region);
place=randperm(regionnumber,blocknumber);
values=randi([1,5],blocknumber,1);
region(place)=values;
board(2:a+1,2:b+1)=region;

emptyplace=find(board==0);
ballplace=emptyplace(randperm(numel(emptyplace),1));
angle=randi([6,9],1,1);
board(ballplace)=angle;

end