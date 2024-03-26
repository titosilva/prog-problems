for f in $(find . -type f)
do
    # echo $f
    strings $f
done