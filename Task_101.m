function retval = Task_101 ()

    A = input("Matrix A: ");


    B = input("Matrix B : ");


    max_value_A = max(max(A));
    fprintf("Max value of A: %d\n", max_value_A);


    if size(A, 2) == size(B, 1)

        result_matrix = A * B;
        fprintf("Multiplication :\n");1
        disp(result_matrix);
    else
        fprintf("Matrix multiplication is not possible.\n");
    end


endfunction
