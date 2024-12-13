for ((i=1; i<=39; i++)); do
    if ! diff <(./a.out < "ecologia/E_$i.in") "ecologia/E_$i.sol" >/dev/null; then
        echo "diferenca em $i"
    fi
done

