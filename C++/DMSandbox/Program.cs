using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using DM8CLI.graphics;
using DM8CLI.math;
using DM8CLI;

namespace DMSandbox
{
    class Program
    {
        static void Main(string[] args)
        {
            Window window = new Window("Test", 1280, 720);

            int[] tids = new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };


            Shader shader = new Shader("shaders/shader.vert", "shaders/shader.frag");

            shader.Enable();
            shader.SetUniformiv("textures", tids);
            shader.Disable();

            Layer layer = new Layer2D(shader);

            Texture texture1 = new Texture(Path.GetFullPath("res/test1.jpg"));
            Texture texture2 = new Texture(Path.GetFullPath("res/test2.jpg"));

            Vec2 size = new Vec2(0.9f, 0.9f);

            Random random = new Random();
            for (float y = 0.0f; y < 9.0f; y += 1.0f)
            {
                for (float x = 0.0f; x < 16.0f; x += 1.0f)
                {
                    int t = random.Next();
                    Renderable2D sprite = new Sprite(new Vec3(x, y, 0), size, (t % 2 == 0) ? texture1 : texture2);
                    layer.Push(sprite);
                }
            }

            while (!window.IsClosed())
            {
                window.Update();
                window.Clear();
                shader.Enable();
                shader.SetUniform2f("light_pos", new Vec2(((float)window.GetMouseX() * 16.0f / 1280.0f), ((float)(9.0f - 9.0f * window.GetMouseY() / 720.0f))));
                shader.Disable();
                layer.Render();

            }

        }
    }
}
