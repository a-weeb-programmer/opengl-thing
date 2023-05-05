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
          libGL
          cmake
          gnumake
          clang
          extra-cmake-modules
        ];
        buildInputs = with pkgs; [
          wayland
          wayland-protocols
          libxkbcommon
          libffi
        ];

        shellHook = ''
          echo ${pkgs.libglvnd.dev}
        '';
      };

      devShells.x86_64-linux.x11 = pkgs.mkShell {
        packages = with pkgs; [
          cmake
          gnumake
          clang
          extra-cmake-modules
        ];
        buildInputs = with pkgs; [
          libGL
          xorg.libX11
          xorg.libXinerama
          xorg.libXi
          xorg.libXcursor
          xorg.libXrandr
        ];

        shellHook = ''
          echo ${pkgs.libglvnd.dev}
        '';
      };

    };
}
