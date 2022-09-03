//
// Created by Mew on 9/2/2022.
//

#ifndef LENS_TEXTURE_LOADER_HPP
#define LENS_TEXTURE_LOADER_HPP

#include <string>
#include "texture.hpp"

namespace lens
{

class TextureLoader
{
public:
    static Texture LoadPNG(const std::string& path);
    static void UnloadTexture(Texture* texture);
};

} // lens

#endif //LENS_TEXTURE_LOADER_HPP
