function view_board(board)
    [rows, cols] = size(board);
    clf;  
    hold on;  
    axis equal; 
    [total_rows, total_columns] = size(board);
    axis([1, total_columns, 1, total_rows]);
    xlabel('Column');
    ylabel('Row');
    title('Bouncing Ball Game Board');
   
    wall_color = [0.3, 0.3, 0.3];   
    block_edge_color = [0, 0.6, 0]; 
    block_fill_color = [0.8, 0.8, 0.8];  
    ball_color = [1, 0, 0];          
    square_size = 0.8;  

    for r = 1:total_rows
        for c = 1:total_columns
            value = board(r, c);
            x = c;
            y = r;

            if value == 5&& (r==1||r==rows||c==1||c==cols)
                x_coords = [x - square_size/2, x + square_size/2, x + square_size/2, x - square_size/2];
                y_coords = [y - square_size/2, y - square_size/2, y + square_size/2, y + square_size/2];
                fill(x_coords, y_coords, wall_color); 
            end

            if value >= 1 && value<=5 && r~=1 && r~=rows && c~=1 && c~=cols
                rectangle('Position', [x - square_size/2, y - square_size/2,  square_size, square_size], 'EdgeColor', block_edge_color,  'FaceColor', block_fill_color);  
                text(x, y, num2str(value), 'HorizontalAlignment', 'center', ...
                     'VerticalAlignment', 'middle', 'FontSize', 12);
            end
            if value >= 6 && value <= 9
                scatter(x, y, 200, ball_color, 'filled'); 
            end
        end
    end
    hold off;
end