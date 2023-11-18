{ stdenv, gcc, gtest, lib }:

stdenv.mkDerivation rec {
  pname = "unit-test-learning";
  version = "0.1";

  src = ./.; 

  buildInputs = [ stdenv gcc gtest ];

  buildPhase = ''
    g++ -o app src/main.cpp
    g++ -o tests test/main_test.cpp -lgtest -lpthread
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp app $out/bin/app
    cp tests $out/bin/tests
  '';

  checkPhase = ''
    ./tests
  '';

  meta = with lib; {
    description = "A simple C++ project with Google Test and Nix";
    platforms = platforms.linux;
  };
}
