with import <nixpkgs> { };

let
  x86prime = pkgs.callPackage ./x86prime_tools/x86prime.nix { };
in
pkgs.mkShell {
  name = "compSys-shell";

  buildInputs = [
    gnumake
    gcc
    gdb
    valgrind
    binutils
    x86prime
  ];

  shellHook = ''
    alias gcc2asm="gcc -Wall -Wextra -pedantic -S -Og -fno-optimize-sibling-calls -no-pie -fno-pie"
  '';
}
