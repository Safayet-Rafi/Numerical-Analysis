function retval = Task_103 ()

function y = f(x)
    y = x.^2 - 4;
end

a = 0;
b = 3;
t = 1e-6;

roots = [];
iterations = 0;

while (b - a) / 2 > t
    c = (a*f(b) - b*f(a)) / (f(b) - f(a));
    roots = [roots; c];

    if f(c) == 0
        break;
    elseif f(a) * f(c) < 0
        b = c;
    else
        a = c;
    end

    iterations = iterations + 1;
end

fprintf('%d iterations needed: %f\n', iterations, roots(end));

x = linspace(0, 3, 100);
y = f(x);

figure;
plot(x, y);
hold on;
plot(roots, f(roots), 'ro');
xlabel('x');
ylabel('function value');
title('False-Position Method ');
legend('function falues', 'Roots');
grid on;


endfunction
