//
// Created by Mew on 9/2/2022.
//

#ifndef LENS_TEXTURE_HPP
#define LENS_TEXTURE_HPP

namespace lens
{
    struct Texture
    {
        int width;
        int height;
        int comp;
        unsigned char* data;
    };
}

#endif //LENS_TEXTURE_HPP
