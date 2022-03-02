gimp -i -b - << EOF
    (define image (car (gimp-file-load RUN-NONINTERACTIVE "$1" "$1")))
    (define drawable (car (gimp-image-get-active-layer image)))
    (define new-filename "$2")
    (gimp-file-save RUN-NONINTERACTIVE image drawable new-filename new-filename)
    (gimp-quit 0)
EOF