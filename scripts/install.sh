#!/usr/bin/env sh
set -eu

output_path="${1:-cputils.h}"
url="https://github.com/himaenshuu/cputils/releases/latest/download/cputils.h"

if command -v curl >/dev/null 2>&1; then
    curl -fsSL "$url" -o "$output_path"
elif command -v wget >/dev/null 2>&1; then
    wget -qO "$output_path" "$url"
else
    echo "curl or wget is required" >&2
    exit 1
fi

echo "Installed cputils.h to $output_path"
