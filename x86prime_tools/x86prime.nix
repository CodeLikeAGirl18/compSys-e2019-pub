{ stdenv, lib, fetchFromGitHub, recurseIntoAttrs, ocamlPackages, ncurses }: with lib;

stdenv.mkDerivation rec {
  name = "x86prime-${version}";
  version = "1f379ee778cfe8ba6ace595a7b1778b6d33269a5"; # commit w/ Profiling

  src = fetchFromGitHub {
    owner = "finnschiermer";
    repo = "x86prime";
    rev = "${version}";
    sha256 = "14yffwdd0f88qnchnps45dm1ivlz748ly4yxqy3prj46j7qw6qja";
  };

  # ncurses is necessary for tput used by ocamlbuild
  buildInputs = [ ncurses (with ocamlPackages; [ ocaml menhir ocamlbuild ]) ];

  installPhase =
  let
    install = p: ''
      ocamlbuild -use-menhir ${p}.native && cp _build/${p}.native "$out/bin/${p}"
    '';
  in ''
    mkdir -p "$out/bin"
    ${concatMapStrings install [ "primify" "prasm" "prun" "prerf" ]}
  '';

  meta = {
    description = "Fairly limited x86 to x86' translator";
  };
}
