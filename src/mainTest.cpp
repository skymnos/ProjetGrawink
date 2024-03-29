#include "../include/Grawink.h"

int main()
{
    GrawEditor canvas = GrawEditor::GetEditor();

    canvas.Resize({0, 0}, 2000, 2000);


    Ellipsis *ellipsis1 = canvas.GetNew<Ellipsis>();
    Polygone *polygon1 = canvas.GetNew<Polygone>();
    Rectangle *rectangle1 = canvas.GetNew<Rectangle>(), *rectangle2 = canvas.GetNew<Rectangle>();
    RegularPolygone  *pentagon1 = canvas.GetNew<RegularPolygone>(), *hexagon1 = canvas.GetNew<RegularPolygone>(), *heptagon1 = canvas.GetNew<RegularPolygone>(), *octogon1 = canvas.GetNew<RegularPolygone>(), *polygon2 = canvas.GetNew<RegularPolygone>();
    Stroke *stroke1= canvas.GetNew<Stroke>();
    Text *text1= canvas.GetNew<Text>();



    ellipsis1->Translate({1000, 1000});
    ellipsis1->Scale(10);
    ellipsis1->Color("red", "red", 1);

    polygon1->Scale(1.5);
    polygon1->Modify({100, 100}, {{200, 100}, {100, 200}}, 20, "red", 2, "red", 0.8);

    rectangle1->Translate({200,200});
    rectangle1->Color("blue", "#115c25", 0.5);
    rectangle1->Scale(4);

    rectangle2->Rotate(45);
    rectangle2->Translate({1000, 100});

    pentagon1->Translate({200, 500});

    hexagon1->Modify({600, 700}, 6, 40, 20, "red", 1);

    heptagon1->Modify({1200, 400}, 7);

    octogon1->Modify({150, 700}, 8);

    polygon2->Modify({600,300}, 13, 60);

    stroke1->Translate({800, 800});

    text1->Modify({1500, 1500}, "Test Text");

    canvas.Add(ellipsis1);
    canvas.Add(polygon1);
    canvas.Add(rectangle1);

    canvas.Add(rectangle2);
    canvas.Select(GrawEditor::ShapeType::All);
    canvas.Print();
    canvas.Delete(rectangle2);
    canvas.Print();
    canvas.Redo();
    canvas.Select(GrawEditor::ShapeType::All);
    canvas.Print();
    canvas.Undo();
    canvas.Print();

    canvas.Add(pentagon1);
    canvas.Add(hexagon1);

    canvas.Select(GrawEditor::ShapeType::Ellipsis, ellipsis1);
    canvas.Print();
    canvas.ExportSVG("export1");

    canvas.Add(heptagon1);
    canvas.Add(octogon1);
    canvas.Add(polygon2);
    canvas.Add(stroke1);
    canvas.Add(text1);

    canvas.Select(GrawEditor::ShapeType::All);
    canvas.Print();
    canvas.ExportSVG("export2");

    canvas.Crop({300, 300}, 1000, 1000);
    canvas.Select(GrawEditor::ShapeType::All);
    canvas.Print();
    canvas.ExportSVG("export3");


    canvas.ClearCanvas();

    return 0;
}