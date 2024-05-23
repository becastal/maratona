for ((i=1; i<=67; i++)); do
    if ! diff <(./a.out < "_comp/K_$i.in") "_comp/K_$i.sol" >/dev/null; then
        echo "diferenca em $i"
    fi
done

