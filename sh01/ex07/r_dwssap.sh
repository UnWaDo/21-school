cat /etc/passwd | grep -v "#" | awk '{if (! (FNR%2) ) print $0}' | rev | awk -F ':*:' '{print $NF}' | sort -r | head -n $((FT_LINE2)) | tail -n $((FT_LINE2-FT_LINE1+1)) | awk '{print $0", "}' | tr -d "\n" | awk {'print substr($0, 1, length($0)-2)"."}'
