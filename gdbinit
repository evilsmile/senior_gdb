define print-node-list
    set $p = $arg0
    printf "node_list: "
    printf "%d", $p->data
    set $p = $p->next
    while $p != 0 
        printf "<->%d", $p->data
        set $p = $p->next
    end
    printf "\n"
end
document print-node-list
print node list given by arg0
end

break 79
run
print-node-list head
