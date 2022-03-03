make

rm -f in out test_out

echo 'Some lines' > in
echo 'Of text' >> in
echo 'And one more' >> in

cmd1="grep s"
cmd2="wc -l"
valgrind ./pipex in "$cmd1" "$cmd2" out
< in $cmd1 | $cmd2 > test_out
if [[ $(diff out test_out) == "" ]]; then
    echo "OK"
else
    echo "KO"
    diff out test_out
fi