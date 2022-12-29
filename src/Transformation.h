#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#define REFERANCE_X 0.9505
#define REFERANCE_Y 1.0000
#define REFERANCE_Z 0.8252

namespace Color
{

    // ---------------------------------------------------------------------------------------------------------------------
    /* RGB to CMY
     * @brief   Convert RGB to CMY
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     * @param   c   Cyan
     * @param   m   Magenta
     * @param   y   Yellow
     */
    void rgb_to_cmy(double r, double g, double b, double &c, double &m, double &y);

    // ---------------------------------------------------------------------------------------------------------------------
    /* CMY to RGB
     * @brief   Convert CMY to RGB
     * @param   c   Cyan
     * @param   m   Magenta
     * @param   y   Yellow
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     */
    void rgb_to_hsv(double r, double g, double b, double &h, double &s, double &v);

    // ---------------------------------------------------------------------------------------------------------------------
    /* RGB to XYZ
     * @brief   Convert RGB to XYZ
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     * @param   x   X
     * @param   y   Y
     * @param   z   Z
     */
    void rgb_to_xyz(double r, double g, double b, double &x, double &y, double &z);

    // ---------------------------------------------------------------------------------------------------------------------
    /* CMY to RGB
     * @brief   Convert CMY to RGB
     * @param   c   Cyan
     * @param   m   Magenta
     * @param   y   Yellow
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     */
    void cmy_to_rgb(double c, double m, double y, double &r, double &g, double &b);

    // ---------------------------------------------------------------------------------------------------------------------
    /* HSV to RGB
     * @brief   Convert HSV to RGB
     * @param   h   Hue
     * @param   s   Saturation
     * @param   v   Value
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     */
    void hsv_to_rgb(double h, double s, double v, double &r, double &g, double &b);

    // ---------------------------------------------------------------------------------------------------------------------
    /* XYZ to RGB
     * @brief   Convert XYZ to RGB
     * @param   x   X
     * @param   y   Y
     * @param   z   Z
     * @param   r   Red
     * @param   g   Green
     * @param   b   Blue
     */
    void xyz_to_rgb(double x, double y, double z, double &r, double &g, double &b);

    // ---------------------------------------------------------------------------------------------------------------------
    /* CMYK to CMY
     * @brief   Convert CMYK to CMY
     * @param   c   Cyan
     * @param   m   Magenta
     * @param   y   Yellow
     * @param   k   Key
     * @param   c_  Cyan
     * @param   m_  Magenta
     * @param   y_  Yellow
     */
    void cmyk_to_cmy(double c, double m, double y, double k, double &c_, double &m_, double &y_);

    // ---------------------------------------------------------------------------------------------------------------------
    /* CMY to CMYK
     * @brief   Convert CMY to CMYK
     * @param   c   Cyan
     * @param   m   Magenta
     * @param   y   Yellow
     * @param   c_  Cyan
     * @param   m_  Magenta
     * @param   y_  Yellow
     * @param   k   Key
     */
    void cmy_to_cmyk(double c, double m, double y, double &c_, double &m_, double &y_, double &k);

    // ---------------------------------------------------------------------------------------------------------------------
    /* LAB to XYZ
     * @brief   Convert LAB to XYZ
     * @param   l   L
     * @param   a   A
     * @param   b   B
     * @param   x   X
     * @param   y   Y
     * @param   z   Z
     */
    void lab_to_xyz(double l, double a, double b, double ref_x, double ref_y, double ref_z, double &x, double &y, double &z);
    
    // ---------------------------------------------------------------------------------------------------------------------
    /* XYZ to LAB
     * @brief   Convert XYZ to LAB
     * @param   x   X
     * @param   y   Y
     * @param   z   Z
     * @param   l   L
     * @param   a   A
     * @param   b   B
     */
    void xyz_to_lab(double x, double y, double z, double ref_x, double ref_y, double ref_z, double &l, double &a, double &b);
} // namespace Color

#endif // TRANSFORMATION_H