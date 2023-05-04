{
  description = "My opengl shit";

  inputs = {
    nixpkgs.url = "github:nixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in
    {
      devShells.x86_64-linux.default = pkgs.mkShell {
        packages = with pkgs; [
          cmake
          gnumake
          clang
        ];
        buildInputs = with pkgs; [
          libglvnd
          glfw
        ];

        shellHook = ''
          echo ${pkgs.libglvnd.dev}
          echo ${pkgs.glfw}
        '';
      };
    };
}
