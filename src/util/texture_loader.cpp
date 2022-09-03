//
// Created by Mew on 9/2/2022.
//

#include "texture_loader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace lens
{

Texture TextureLoader::LoadPNG(const std::string& path)
{
    Texture tex{};
    tex.data = stbi_load(path.c_str(), &tex.width, &tex.height, &tex.comp, STBI_rgb_alpha);
    return tex;
}

void TextureLoader::UnloadTexture(Texture* texture)
{
    stbi_image_free(texture->data);
}

}
