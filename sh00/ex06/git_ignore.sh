#!/bin/sh
dir=$(git rev-parse --show-toplevel)
find "$dir" | git check-ignore --stdin
