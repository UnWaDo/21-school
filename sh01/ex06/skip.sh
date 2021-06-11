ls -l | awk '{if (FNR % 2) print $0}'
