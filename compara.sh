for ((i=1; i<=36; i++)); do
    if ! diff <(./a.out < "input/J_$i") "output/J_$i" >/dev/null; then
        echo "diferenca em $i"
    fi
done

