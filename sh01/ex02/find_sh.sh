find . -name "*.sh" -print | awk '{FS="/"; print $NF}' | awk '{print substr($0, 1, length($0)-3)}'
