function solve(N, E: longint; var C: array of longint): longint;
begin
    (* insert your code here *)
    solve := 42;
end;


const
    MAXN = 100000;
var
    N, E, i  : longint;
    C        : array[0..MAXN-1] of longint;
    fr, fw   : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, E);
    for i:=0 to N-1 do
        read(fr, C[i]);

    writeln(fw, solve(N, E, C));
    close(fr);
    close(fw);
end.
