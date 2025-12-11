#include "VisualizerPanel.hpp"
#include "overlay/OverlayEngine.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

namespace vc {

VisualizerPanel::VisualizerPanel(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
}

void VisualizerPanel::setOverlayEngine(OverlayEngine* engine) {
    if (visualizer_) {
        visualizer_->setOverlayEngine(engine);
    }
}

void VisualizerPanel::setupUI() {
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(4);
    
    // Visualizer widget
    visualizer_ = new VisualizerWidget(this);
    visualizer_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    visualizer_->setMinimumSize(320, 240);
    layout->addWidget(visualizer_, 1);
    
    // Control bar
    auto* controlBar = new QWidget();
    controlBar->setMaximumHeight(40);
    auto* controlLayout = new QHBoxLayout(controlBar);
    controlLayout->setContentsMargins(8, 4, 8, 4);
    controlLayout->setSpacing(8);
    
    prevPresetButton_ = new QPushButton("◀");
    prevPresetButton_->setFixedSize(28, 28);
    prevPresetButton_->setToolTip("Previous preset");
    connect(prevPresetButton_, &QPushButton::clicked, this, [this] {
        visualizer_->projectM().previousPreset();
    });
    controlLayout->addWidget(prevPresetButton_);
    
    presetLabel_ = new QLabel("No preset");
    presetLabel_->setAlignment(Qt::AlignCenter);
    presetLabel_->setStyleSheet("color: #00ff88; font-weight: bold;");
    controlLayout->addWidget(presetLabel_, 1);
    
    nextPresetButton_ = new QPushButton("▶");
    nextPresetButton_->setFixedSize(28, 28);
    nextPresetButton_->setToolTip("Next preset");
    connect(nextPresetButton_, &QPushButton::clicked, this, [this] {
        visualizer_->projectM().nextPreset();
    });
    controlLayout->addWidget(nextPresetButton_);
    
    lockButton_ = new QPushButton("🔓");
    lockButton_->setFixedSize(28, 28);
    lockButton_->setCheckable(true);
    lockButton_->setToolTip("Lock preset");
    connect(lockButton_, &QPushButton::clicked, this, [this](bool checked) {
        visualizer_->projectM().lockPreset(checked);
        lockButton_->setText(checked ? "🔒" : "🔓");
        emit lockPresetToggled(checked);
    });
    controlLayout->addWidget(lockButton_);
    
    fullscreenButton_ = new QPushButton("⛶");
    fullscreenButton_->setFixedSize(28, 28);
    fullscreenButton_->setToolTip("Fullscreen");
    connect(fullscreenButton_, &QPushButton::clicked, this, [this] {
        visualizer_->toggleFullscreen();
        emit fullscreenRequested();
    });
    controlLayout->addWidget(fullscreenButton_);
    
    fpsLabel_ = new QLabel("0 FPS");
    fpsLabel_->setFixedWidth(60);
    fpsLabel_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    fpsLabel_->setStyleSheet("color: #888888; font-size: 11px;");
    controlLayout->addWidget(fpsLabel_);
    
    layout->addWidget(controlBar);
    
    // Connect visualizer signals
    connect(visualizer_, &VisualizerWidget::fpsChanged, this, &VisualizerPanel::updateFPS);
    
    visualizer_->projectM().presetChanged.connect([this](const std::string& name) {
        QMetaObject::invokeMethod(this, [this, name] {
            updatePresetName(QString::fromStdString(name));
        });
    });
}

void VisualizerPanel::updatePresetName(const QString& name) {
    QString display = name;
    if (display.length() > 50) {
        display = display.left(47) + "...";
    }
    presetLabel_->setText(display);
    presetLabel_->setToolTip(name);
}

void VisualizerPanel::updateFPS(f32 fps) {
    fpsLabel_->setText(QString("%1 FPS").arg(static_cast<int>(fps)));
}

} // namespace vc
