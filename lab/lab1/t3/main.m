board = init_board();

fprintf('Game Started.\n');
while true
    view_board(board);
    pause(0.1);
    board = update_board(board);
end